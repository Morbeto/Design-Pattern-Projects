#pragma once
#include<iostream>
#include<cstring>
#include"helpText.h"

class Label {
private:
    std::unique_ptr<HelpTextBridge> helper;

public:
    virtual ~Label() = default;
    virtual std::string getText() const = 0;

    std::string getHelper() const;
    bool hasHelper() const;
    void setHelper(std::unique_ptr<HelpTextBridge> text);
};