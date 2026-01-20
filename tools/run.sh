#!/usr/bin/env bash

set -e

BUILD_DIR=build
TEST_DIR=tests/lexer
EXPECTED_DIR=tests/lexer/expected
LEXER_BIN=$BUILD_DIR/lexer_test

# ----------------------------
# Build
# ----------------------------
build() {
  mkdir -p $BUILD_DIR
  cmake -S . -B $BUILD_DIR
  cmake --build $BUILD_DIR
}

# ----------------------------
# Test lexer
# ----------------------------
test_lexer() {
  build

  mkdir -p $EXPECTED_DIR

  for testfile in $TEST_DIR/*.c; do
    name=$(basename "$testfile" .c)
    expected="$EXPECTED_DIR/$name.tokens"

    echo "Running lexer test: $name"

    if [ ! -f "$expected" ]; then
      echo "  → expected output missing, creating it"
      $LEXER_BIN "$testfile" > "$expected"
    else
      $LEXER_BIN "$testfile" > /tmp/$name.tokens
      diff -u "$expected" /tmp/$name.tokens
    fi
  done

  echo "All lexer tests passed"
}

# ----------------------------
# CLI dispatch
# ----------------------------
case "$1" in
  build)
    build
    ;;
  test)
    if [ "$2" = "lexer" ]; then
      test_lexer
    else
      echo "Usage: ./tools/run.sh test lexer"
      exit 1
    fi
    ;;
  *)
    echo "Usage:"
    echo "  ./tools/run.sh build"
    echo "  ./tools/run.sh test lexer"
    exit 1
    ;;
esac
