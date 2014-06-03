.PHONY: clean All

All:
	@echo "----------Building project:[ tepp - Debug ]----------"
	@cd "src" && $(MAKE) -f  "tepp.mk"
clean:
	@echo "----------Cleaning project:[ tepp - Debug ]----------"
	@cd "src" && $(MAKE) -f  "tepp.mk" clean
