//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include "IPv4RangeExplorer.h"
#include <iostream>
#include <string>
#include <vector>

class IPv4 {
private:
    std::string dottedIp;
    int addressOctets[4] = { 0, 0, 0, 0 };

public:

    void splitDottedIp(const std::string& ip) {
        std::string octet = "";
        int index = 0;
        for (char ch : ip) {
            if (ch != '.') {
                octet += ch;
            }
            else {
                addressOctets[index] = std::stoi(octet);
                index++;
                octet = "";
            }
        }
        addressOctets[3] = std::stoi(octet);
    }

    void readDottedIp() {
        std::string inputIp;
        std::cin >> inputIp;
        dottedIp = inputIp;

        splitDottedIp(dottedIp);
    }


    void displayAddress() {
        std::cout << "( ";
        for (int i = 0; i < 4; ++i) {
            std::cout << addressOctets[i];
            if (i < 3) std::cout << " , ";
        }
        std::cout << " )" << std::endl;
    }

    void increment() {
        for (int i = 3; i >= 0; --i) {
            if (addressOctets[i] < 255) {
                addressOctets[i]++;
                break;
            }
            else {
                addressOctets[i] = 0;
            }
        }
    }

    bool operator<(const IPv4& other) const {
        for (int i = 0; i < 4; ++i) {
            if (addressOctets[i] < other.addressOctets[i]) return true;
            if (addressOctets[i] > other.addressOctets[i]) return false;
        }
        return false;
    }



};

int main() {
    IPv4 startIp, endIp;
    std::cout << "Please enter the start IP address in dotted format: ";
    startIp.readDottedIp();
    std::cout << "Please enter the end IP address in dotted format: ";
    endIp.readDottedIp();

    for (IPv4 currentIp = startIp; currentIp < endIp; currentIp.increment()) {
        currentIp.displayAddress();
    }

    return 0;
}