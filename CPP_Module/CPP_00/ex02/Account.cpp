#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
{
    static int index;

    _displayTimestamp();
    this->_accountIndex = index++;
    std::cout << "index:" << this->_accountIndex << ";";
    this->_amount = initial_deposit;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += this->_amount;
    _totalNbDeposits += this->_nbDeposits;
    _totalNbWithdrawals += this->_nbWithdrawals;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
    time_t timestamp;
    char    buff[16];

    time(&timestamp);
    strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", localtime(&timestamp));
    std::cout << "[" << buff << "] ";
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:";
    if (checkAmount() < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return (0);
    }
    std::cout << withdrawal << ";";
    this->_amount -= withdrawal;
    std::cout << "amount:" << this->_amount << ";";
    this->_nbWithdrawals ++;
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return (1);
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_amount += deposit;
    std::cout << "amount:" << this->_amount << ";";
    this->_nbDeposits ++;
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

void	Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}