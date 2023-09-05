
C_FILES = $(wildcard *.c)
O_FILES = $(patsubst %.c, %.o, $(C_FILES))
H_FILES = $(wildcard *.h)

runtime: $(C_FILES)
	gcc $^ -o $@

%.o: %.c $(H_FILES)
	gcc $< -c -o $@ -std=c17 -Wall -Wextra -Wpedantic

clean:
	rm -rf $(O_FILES) runtime

