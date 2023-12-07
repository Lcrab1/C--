#pragma once
#include"time.h"
#include"customer.h"
#include"print.h"

uint32_t getShortest(vector<queue<Customer>>* cashier);

void chooseCashier(vector<queue<Customer>>* cashier, queue<Customer>* q, Customer cus);

void updateQueueQ(vector<queue<Customer>>* cashier, queue<Customer>* q);

void deleteTemp(Customer temp);

void enterCashier(vector<queue<Customer>>* cashier, queue<Customer>* q, Time& time);