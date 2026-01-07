#!/bin/bash

RED="\033[31m"
GREEN="\033[32m"
CYAN="\033[36m"
YELLOW="\033[33m"
MAGENTA="\033[35m"
RESET="\033[0m"
BOLD="\033[1m"

PRINT_ARGS=false
BENCH=false
SIMPLE=false
COMPLEXE=false
MEDIUM=false

for arg in "$@"; do
    case $arg in
        -n) PRINT_ARGS=true ;;
        --bench) BENCH=true ;;
        --simple) SIMPLE=true ;;
        --complexe) COMPLEXE=true ;;
        --medium) MEDIUM=true ;;
        *) ;;
    esac
done

make -s
make bonus -s

SIZES=(10 50 100 250 500)

test_size() {
    local SIZE=$1
    shift
    local PS_FLAGS="$@"

    printf "%b\n" "${CYAN}${BOLD}=== Test $SIZE nombres ===${RESET}"

    ARGS=$(seq -100000 100000 | shuf -n $SIZE)

    [ "$PRINT_ARGS" = true ] && printf "%b %b\n" "${CYAN}Arguments:${RESET}" "$ARGS"

    local PUSH_FLAGS=""
    [ "$SIMPLE" = true ] && PUSH_FLAGS="$PUSH_FLAGS --simple"
    [ "$COMPLEXE" = true ] && PUSH_FLAGS="$PUSH_FLAGS --complexe"
    [ "$MEDIUM" = true ] && PUSH_FLAGS="$PUSH_FLAGS --medium"

    if [ "$BENCH" = true ]; then
        ./push_swap $PUSH_FLAGS --bench $ARGS
        return 0
    fi

    OPS=$(./push_swap $PUSH_FLAGS $ARGS)
    RET=$?
    COUNT=$(printf "%s\n" "$OPS" | wc -l)
    RESULT=$(printf "%s\n" "$OPS" | ./checker_linux $ARGS)

    if [ $RET -ne 0 ]; then
        printf "%b\n" "${RED}✘ CRASH${RESET}"
        printf "%b %b\n" "${YELLOW}Arguments utilisés:${RESET}" "$ARGS"
        printf "\n%b\n" "${CYAN}${BOLD}=== Valgrind ===${RESET}"
        valgrind ./push_swap $PUSH_FLAGS $ARGS
        return 1
    fi

    if [ "$RESULT" != "OK" ]; then
        printf "%b\n" "${RED}✘ KO${RESET}"
        printf "%b %b\n" "${YELLOW}Arguments utilisés:${RESET}" "$ARGS"
        printf "\n%b\n" "${CYAN}${BOLD}=== Valgrind ===${RESET}"
        valgrind ./push_swap $PUSH_FLAGS $ARGS
        return 1
    fi

    VALGRIND_OUT=$(valgrind --leak-check=full ./push_swap $PUSH_FLAGS $ARGS 2>&1)
    echo "$VALGRIND_OUT" | grep -q "All heap blocks were freed -- no leaks are possible"
    NO_LEAKS=$?

    if [ $NO_LEAKS -ne 0 ]; then
        printf "%b\n" "${RED}✘ LEAKS${RESET}"
        printf "%b %b\n" "${YELLOW}Arguments utilisés:${RESET}" "$ARGS"
        printf "\n%b\n" "${CYAN}${BOLD}=== Valgrind ===${RESET}"
        printf "%s\n" "$VALGRIND_OUT"
        return 1
    fi

    printf "%b\n" "${GREEN}✔ OK${RESET}"
    printf "%b %b\n" "${YELLOW}Instructions:${RESET}" "${BOLD}$COUNT${RESET}"
}

for SIZE in "${SIZES[@]}"; do
    if [ "$MEDIUM" = true ] && [ $SIZE -gt 100 ]; then
        continue
    fi

    if [ "$COMPLEXE" = true ] && [ $SIZE -lt 100 ]; then
        continue
    fi

    test_size $SIZE "$@"
done

check_error() {
    local ARGS="$1"
    local PS_FLAGS="$2"
    local EXPECTED="$3"

    [ -z "$ARGS" ] && return 0

    printf "%b\n" "${CYAN}${BOLD}=== Check Error ===${RESET}"
    [ "$PRINT_ARGS" = true ] && printf "%b %b\n" "${CYAN}Arguments:${RESET}" "$ARGS"

    RESULT=$(./push_swap $PS_FLAGS $ARGS 2>&1)

    printf "%b %b\n" "${YELLOW}Arguments utilisés:${RESET}" "$ARGS"
    printf "%b %b\n" "${YELLOW}Flags utilisés:${RESET}" "$PS_FLAGS"
    if [ "$RESULT" = "$EXPECTED" ]; then
        printf "%b\n" "${GREEN}✔ Résultat attendu: $EXPECTED${RESET}"
    else
        printf "%b\n" "${RED}✘ Résultat inattendu !${RESET}"
        printf "%b %b\n" "${YELLOW}Attendu:${RESET}" "$EXPECTED"
        printf "%b %b\n" "${YELLOW}Obtenu:${RESET}" "$RESULT"

        VALGRIND_OUT=$(valgrind --leak-check=full ./push_swap $PS_FLAGS $ARGS 2>&1)
        echo "$VALGRIND_OUT" | grep -q "All heap blocks were freed -- no leaks are possible"
        NO_LEAKS=$?

        if [ $NO_LEAKS -ne 0 ]; then
            printf "%b\n" "${RED}✘ LEAKS SUR TEST${RESET}"
            printf "%s\n" "$VALGRIND_OUT"
        fi
    fi
}


check_error "4 3 2 1 one" "--medium" "Error"
check_error "4 3 2 1" "--medium --foo" "Error"
check_error " " " " ""
check_error " " "--simple" "Error"
check_error "4 4 3 2 1" "--simple" "Error"