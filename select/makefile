.PHONY:all
all:select client
client:client.c
	gcc -o $@ $^
select:select.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -f select client

