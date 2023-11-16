# Compiler
CXX = g++

# Executable name
CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-sign-compare

.PHONY: make-lcs make-sim test-lcs test-sim

make-all: make-lcs make-sim

make-lcs:
	@OUTPUT=$$(make lcs 2>&1) ;\
	CODE=$$? ;\
	if [ $$CODE -eq 0 ] && [ -e "lcs" ]; then \
		echo "Successfully compiled lcs!"; \
	else \
		echo "Cannot compile lcs using \"make lcs\"!"; \
		exit 1; \
	fi

make-sim:
	@OUTPUT=$$(make sim 2>&1) ;\
	CODE=$$? ;\
	if [ $$CODE -eq 0 ] && [ -e "sim" ]; then \
		echo "Successfully compiled sim!"; \
	else \
		echo "Cannot compile sim using \"make sim\"!"; \
		exit 1; \
	fi

test-lcs: make-lcs
	@echo "Checking correctness of lcs ..."
	@OUTPUT=$$(./lcs ACTGATTCA ACGGATGCA) ;\
	if echo "$$OUTPUT" | grep -Eiq "LCS: 7 ACGATCA"; then \
		echo "Test 1 result correct"; \
	else \
		echo "Test 1 result wrong"; \
		exit 1; \
	fi
	@OUTPUT=$$(./lcs GTCGTTCAGTTACGTCAGT GTATCGTGCACCTTTGTAAGC) ;\
	if echo "$$OUTPUT" | grep -Eiq "LCS: 13 GTCGTCATTGTAG"; then \
		echo "Test 2 result correct"; \
	else \
		echo "Test 2 result wrong"; \
		exit 1; \
	fi
	@OUTPUT=$$(./lcs AACCTTGG AAACCGTTGG) ;\
	if echo "$$OUTPUT" | grep -Eiq "LCS: 8 AACCTTGG"; then \
		echo "Test 3 result correct"; \
	else \
		echo "Test 3 result wrong"; \
		exit 1; \
	fi

test-sim: make-sim
	@echo "Checking correctness of sim ..."
	@OUTPUT=$$(./sim seqs.txt) ;\
	if echo "$$OUTPUT" | grep -Eiq "L  D  D  L  D  M  L"; then \
		echo "Line 1 correct"; \
	else \
		echo "Line 1 wrong"; \
		exit 1; \
	fi
	@OUTPUT=$$(./sim seqs.txt) ;\
	if echo "$$OUTPUT" | grep -Eiq "D  D  L  D  L  H"; then \
		echo "Line 2 correct"; \
	else \
		echo "Line 2 wrong"; \
		exit 1; \
	fi
