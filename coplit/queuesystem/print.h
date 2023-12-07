#pragma once
#include"time.h"
#include"customer.h"
#include<vector>
#include<queue>
#include<iomanip>
void printEnterCus(Customer cus, vector<queue<Customer>>* cashier);
void printLeaveCus(Customer cus, vector<queue<Customer>>* cashier);