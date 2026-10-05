.PHONY: fmt
fmt:
	@find . -regex '.*\.\(cpp\|hpp\|cc\|cxx\|c\|h\)' -exec clang-format -i {} +
	@echo "All C++ files formatted successfully!"
