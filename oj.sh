#!/bin/bash

COLOR_SUCCESS="\e[32m"
COLOR_ERROR="\e31m"
COLOR_OFF="\e[m"
TEST_CASE_DIR="test_case"

# Register contest name to environment variable to construct contest url later.
# @arg contest_name Contest name to try.
init() {
    export CONTEST_NAME=$1
    echo -e "${COLOR_SUCCESS}Registered ${CONTEST_NAME} to environment variable.${COLOR_OFF}"
}

# Download all test cases in a contest specified by CONTEST_NAME.
download_all_case() {
    mkdir -p $TEST_CASE_DIR
    for problem in {a..z}
    do
        echo $problem
        contest_url="https://atcoder.jp/contests/${CONTEST_NAME}/tasks/${CONTEST_NAME}_${problem}"
        oj d -d "${TEST_CASE_DIR}/${problem}" ${contest_url}
        if [ $? -gt 0 ]; then
            echo -e "${COLOR_SUCCESS}Download finished.${COLOR_OFF}"
            break
        fi
    done
}

# Compile source code and check if test cases are satisfied.
# @arg problem Probloem id to test(a, b, c, ...).
test_cases() {
    echo "Compiling source code..."
    g++ -std=gnu++17 -o "${1}.out" "${1}.cpp"
    if [ $? -gt 0 ]; then
        echo "${COLOR_ERROR}Compilation failed${COLOR_OFF}"
        exit $?
    fi
    echo -e "${COLOR_SUCCESS}Compiled successful.${COLOR_OFF}"
    oj t -d "${TEST_CASE_DIR}/${1}" -c "./${1}.out"
}

# Submit source code.
# @arg problem Probloem id to test(a, b, c, ...).
submit() {
    problem=$1
    contest_url="https://atcoder.jp/contests/${CONTEST_NAME}/tasks/${CONTEST_NAME}_${problem}"
    oj s -l C++ ${contest_url} "${problem}.cpp"
}

if [ $# -eq 0 ]; then
    echo -e "${COLOR_SUCCESS}Wrapper script for online-judge-tools${COLOR_OFF}"
    echo "    -i [contest_name]  Specify a contest for later commands"
    echo "    -d                 Download all test cases in the contest"
    echo "    -t [problem_id]    Test sample cases"
    echo "    -s [problem_id]    Submit source code"
fi

while getopts "i:dt:s:" OPTS
do
    case $OPTS in
        i )
            init $OPTARG
            ;;
        d )
            download_all_case
            ;;
        t )
            test_cases "$OPTARG"
            ;;
        s )
            submit "$OPTARG"
            ;;
    esac
done
