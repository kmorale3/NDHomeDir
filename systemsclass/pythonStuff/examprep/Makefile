test:
	@$(MAKE) -sk test-all

test-all:	test-scripts test-translations

test-scripts:
	curl -sL https://yld.me/raw/hx5p > test_translations.sh
	chmod +x test_translations.sh

test-translations:
	./test_translations.sh
