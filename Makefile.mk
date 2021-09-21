makedir = .
bin     = $(makedir)/bin
src     = $(makedir)/game-files

includelist = -I$(src)
cxxcommon   = -std=c++17 -g -Wall -Wextra -Wpedantic -Wfloat-equal $(includelist)

.PHONY: \
	all \
	clean \
	directories \
	run

all: directories $(bin)/casino

clean:
	-@rm $(bin)/*

directories:
	@mkdir -p $(bin)

run: all
	@$(bin)/practicas

$(bin)/casino: $(src)/casino.cpp \
		$(src)/auxfunc.h \
		$(src)/blackjack.h \
		$(src)/coinflip.h \
		$(src)/mayorMenor.h \
		$(src)/ruleta.h
	$(CXX) $(CXXFLAGS) -o $@ $^ $(libs)
