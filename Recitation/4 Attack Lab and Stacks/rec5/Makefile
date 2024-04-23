PROJECTS =

.PHONY: all
all: $(PROJECTS)
	(cd src && make)
	(cd inputs && make)

.PHONY: clean
clean:
	(cd src && make clean)
	(cd inputs && make clean)

input_names = input1 input2 input3 input4
input_files := $(foreach name, $(input_names), $(name).bin)

.PHONY: test
test: 
	for input in $(input_files); do \
		echo "Testing $$input"; \
		./activity < inputs/$$input; \
	done

