CFLAGS := -Wall

.PHONY: all clean check

EXE := rect cyl

all: $(EXE) check

$(EXE): %: %.cc
	@echo Compiling $@
	@g++ $(CFLAGS) $^ -o $@

check: $(EXE) check.sh
	@./check.sh
	@echo Checked $<

clean:
	@rm -fv $(EXE)

