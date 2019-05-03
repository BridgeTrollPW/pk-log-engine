.PHONY: clean All

All:
	@echo "----------Building project:[ log-engine - Debug ]----------"
	@"$(MAKE)" -f  "log-engine.mk"
clean:
	@echo "----------Cleaning project:[ log-engine - Debug ]----------"
	@"$(MAKE)" -f  "log-engine.mk" clean
