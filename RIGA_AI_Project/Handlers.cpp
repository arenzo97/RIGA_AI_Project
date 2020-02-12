#pragma once
#include <string>

using std::string;

class Handler
{
public:
	virtual Handler *SetNext(Handler *handler) = 0;
	virtual string Handle(string request) = 0;
};

class AbstractHandler : public Handler
{
private:
	Handler *next_handler_;

public:
	AbstractHandler() : next_handler_(nullptr) {

	}

	Handler *SetNext(Handler *handler) override
	{
		this->next_handler_ = handler;
		return handler;

	}

	string Handle(string request) override {
		if (this->next_handler_)
		{
			return this->next_handler_->Handle(request);
		}
		return{};
	}
};