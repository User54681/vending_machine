#include "candy_machine.h"
#include <iostream>

void show_menu();
void sell_product(dispenser_type& product, cash_register& money);

int main()
{
    setlocale(LC_ALL, "Rus");
    show_menu();
}

void show_menu() {
    std::cout << "* * * МЕНЮ * * *" << "\n";
    std::cout << "Выберите цифру, чтобы купить..." << "\n";
    std::cout << "1. Конфеты" << "\n";
    std::cout << "2. Чипсы" << "\n";
    std::cout << "3. Жвачка" << "\n";
    std::cout << "4. Печенье" << "\n";
    std::cout << "5. Закрыть меню" << "\n";

    dispenser_type candy(10, 30); 
    dispenser_type chips(5, 80);
    dispenser_type gum(15, 30); 
    dispenser_type cookies(10, 50); 
    cash_register money;
    int product;
    std::cin >> product;
    switch (product){
        case 1:
            sell_product(candy, money);
            break;
        case 2:
            sell_product(chips, money);
            break;
        case 3:
            sell_product(gum, money);
            break;
        case 4:
            sell_product(cookies, money);
            break;
        case 5:
            break;
        default:
            std::cout << "Введено некорректное значение. Попробуйте заново." << "\n";
            std::cin >> product;
            break;
    }
}

void sell_product(dispenser_type& product, cash_register& money) {
    int amount;
    if (product.get_no_of_items() > 0) {
        std::cout << "Данный товар стоит " << product.get_cost() << " рублей. Пожалуйста, введите оплату: ";
        std::cin >> amount;
        while (amount < product.get_cost()) {
            std::cout << "Оплата не прошла, недостаточно средств. Пожалуйста, повторите попытку" << "\n";
            std::cin >> amount;
        }

        if (amount == product.get_cost()) {
            money.accept_amount(amount);
            std::cout << "Оплата прошла успешно. Пожалуйста, заберите ваш товар." << "\n";
        }
        else {
            money.accept_amount(product.get_cost());
            std::cout << "Оплата прошла успешно. Пожалуйста, заберите ваш товар." << "\n";
            std::cout << "Заберите сдачу: " << amount - product.get_cost() << "\n";
        }
        product.make_sale();
    }
    else {
        std::string answer;
        std::cout << "К сожалению, данный товар закончился. Желаете продолжить покупки?" << "\n";    
        std::cin >> answer;

        if (answer == "да" or answer == "Да" or answer == "yes" or answer == "Yes") show_menu();
    }
}