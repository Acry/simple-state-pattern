define colorecho
      @tput setaf 2
      @echo $1
      @tput sgr0
endef

CFLAGS   =  -Wall -Wextra -mtune=native `sdl2-config --cflags`
LDFLAGS  = `sdl2-config --libs` -lSDL2_image -lSDL2_ttf

TARGETS = example

.PHONY: all
all: $(TARGETS)

example:   helper.c  example.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

.PHONY: clean
clean:
	@rm $(TARGETS) 2>/dev/null || true
	$(call colorecho,"It is clean now.")

