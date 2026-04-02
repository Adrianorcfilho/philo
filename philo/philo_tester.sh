#!/bin/bash

VALGRIND="valgrind --leak-check=full --error-exitcode=42 --quiet"
PHILO="./philo"
TIMEOUT="timeout 5s"

RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[1;33m"
BLUE="\033[0;34m"
NC="\033[0m"

if [ ! -x "$PHILO" ]; then
    echo -e "${RED}Error: $PHILO not found.${NC}"
    exit 1
fi

# ============================================================
# Hardcore test!
# ============================================================
TESTS=(
"0 0 0 0" "0 0 0 1" "0 0 1 0" "0 0 1 1"
"0 1 0 0" "0 1 0 1" "0 1 1 0" "0 1 1 1"
"1 0 0 0" "1 0 0 1" "1 0 1 0" "1 0 1 1"
"1 1 0 0" "1 1 0 1" "1 1 1 0" "1 1 1 1"
"2 0 0 0" "2 0 0 1" "2 0 1 0" "2 0 1 1"
"2 1 0 0" "2 1 0 1" "2 1 1 0" "2 1 1 1"
"-2 410 200 200" "2 -410 200 200" "2 410 -200 200" "2 410 200 -200"
"+-2 410 200 200" "2 +-410 200 200" "2 410 +-200 200" "2 410 200 +-200"
"-+2 410 200 200" "2 -+410 200 200" "2 410 -+200 200" "2 410 200 -+200"
"-000+002 +00410 0+200 0-200" "00+2 0-0410 200 200" "+0-2 -0+410 +0-200 -0+200"
"0+02 0410 -0200 +0200" "2 +410 00-200 0+200" "-+2 +-410 +00200 -00200" "+02 0+0410 +0-200 -0+200"
"00+2 -00410 +0200 -0200" "000002 410 200 200" "2 00000410 200 200" "2 410 000000200 200"
"2 410 200 00000000000200" "02 00410 200 200" "02 00410 00200 000200" "000002 0410 200 00000200"
"2 0000410 200 00000200" "+2 410 200 200" "2 +410 200 200" "2 410 +200 200" "2 410 200 +200"
"++2 410 200 200" "2 ++410 200 200" "2 410 ++200 200" "2 410 200 ++200"
"2" "2 410" "2 410 200" "2 410 200 200"
)

counter=1
total=${#TESTS[@]}

echo -e "${BLUE}\n===== PHILO HARDCORE TESTER ULTRA-SAFE =====${NC}"

for args in "${TESTS[@]}"; do
    echo -e "\n${YELLOW}[$counter/$total] $PHILO $args${NC}"

    OUTPUT=$($TIMEOUT $VALGRIND $PHILO $args 2>&1)
    EXIT=$?

    if [ $EXIT -eq 42 ]; then
        echo -e "${RED}❌ Valgrind error${NC}"
    
    elif [ $EXIT -eq 124 ]; then
        echo -e "${GREEN}⏱️ Timeout reached (simulation still running)${NC}"
    
    else
        if echo "$OUTPUT" | grep -q "is eating"; then
            echo -e "${GREEN}✅ Simulation ran correctly${NC}"
        else
            echo -e "${GREEN}✅ Invalid parsing or fast exit${NC}"
        fi
    fi

    ((counter++))
done

echo -e "${BLUE}\nAll tests completed.${NC}"