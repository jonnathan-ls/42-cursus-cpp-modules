#!/bin/bash

RESET="\033[0m"
GREEN="\033[32m"
CYAN="\033[36m"
YELLOW="\033[33m"

BIN="./convert"

run_test() {
    printf "${CYAN}▸ ${RESET}\"${YELLOW}%s${RESET}\"\n" "$1"
    $BIN "$1"
    echo
}

section() {
    printf "${GREEN}━━━ %s ━━━${RESET}\n\n" "$1"
}

# Build
make re > /dev/null 2>&1 || { echo "❌ Build failed"; exit 1; }
printf "\n🧪 ScalarConverter Test Suite${RESET}\n\n"

# ── Char literals ──
section "📝 Char literals"
for t in "a" "Z" "*" " " "@" "(" "+" "-" "."; do run_test "$t"; done

# ── Int literals ──
section "🔢 Int literals"
for t in "0" "42" "-42" "2147483647" "-2147483648"; do run_test "$t"; done

# ── Int overflow → Double ──
section "💥 Int overflow → Double"
for t in "2147483648" "-2147483649" "99999999999"; do run_test "$t"; done

# ── Float literals ──
section "🔬 Float literals"
for t in "0.0f" "42.0f" "-4.2f" "4.2f" ".5f"; do run_test "$t"; done

# ── Double literals ──
section "📐 Double literals"
for t in "0.0" "42.0" "-4.2" "4.2" ".5" "-.2"; do run_test "$t"; done

# ── Pseudo-literals ──
section "🔮 Pseudo-literals"
for t in "nan" "nanf" "+inf" "+inff" "-inf" "-inff" "inf" "inff"; do run_test "$t"; done

# ── Invalid inputs ──
section "🚫 Invalid inputs"
for t in "" "	" "abc" "42abc" "--42" "42.42.42" "-f" ".-2" "+.2f" "12.3d" "NaN" "NANF" "INFF" "Inf"; do run_test "$t"; done

# ── Edge cases ──
section "🎯 Edge cases"
for t in "1232133222" "0.0000001" "-0" "+0"; do run_test "$t"; done

printf "✅ All tests executed.${RESET}\n\n"
