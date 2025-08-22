#pragma once
#include"labels/Label.h"
#include"transformations/transFactory.h"
#include<vector>

class CompositeTransformation : public Transformation {
private:
    std::vector<std::shared_ptr<Transformation>> transformations;

public:
    explicit CompositeTransformation(const std::string&);
    ~CompositeTransformation() = default;

    void addTransformation(std::shared_ptr<Transformation> transformation);
    void addTransformation(std::string& );

    void createTransformation(const std::string&);


    std::string transform(const std::string& text) const override;
};