#include "candy_machine.h"

cash_register::cash_register() {
	cash_on_hand = 500;
}
cash_register::cash_register(int cash_in) {
	cash_on_hand = cash_in;
}
int cash_register::get_current_balance() {
	return cash_on_hand;
}
void cash_register::accept_amount(int amount) {
	cash_on_hand += amount;
}

dispenser_type::dispenser_type() {
	number_of_items = 50;
	type_cost = 50;
}
dispenser_type::dispenser_type(int number_of_items, int type_cost) {
	this->number_of_items = number_of_items; 
	this->type_cost = type_cost; 
}
int dispenser_type::get_no_of_items() {
	return number_of_items;
}
int dispenser_type::get_cost() {
	return type_cost;
}
void dispenser_type::make_sale() {
	--number_of_items;
}