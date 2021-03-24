repl-build.out: midterm_template.c
	gcc -o $@ $^

.PHONY: run
run: repl-build.out points.txt output.txt
	./$^

.PHONY: clean

clean:
	rm -f repl-build.out
