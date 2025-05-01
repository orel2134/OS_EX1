
.PHONY: all clean q1 q2 q3 q4 q5 q6 q7

#
all: q1 q2 q3 q4 q5 q6 q7

#
q1 q2 q3 q4 q5 q6 q7:
	@echo "===> Building $@..."
	$(MAKE) -C $@ all

#
clean:
	@$(MAKE) -C q1 clean
	@$(MAKE) -C q2 clean
	@$(MAKE) -C q3 clean
	@$(MAKE) -C q4 clean
	@$(MAKE) -C q5 clean
	@$(MAKE) -C q6 clean
	@$(MAKE) -C q7 clean
