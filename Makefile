CFLAGS := -Wall

.PHONY: all clean check

EXE := grid_loop

all: $(EXE) check

$(EXE): %: %.cc
	@echo Compiling $@
	@g++ $(CFLAGS) $^ -o $@

check: $(EXE) check.sh
	@./check.sh
	@echo Checked $<

clean:
	@rm -fv $(EXE)

