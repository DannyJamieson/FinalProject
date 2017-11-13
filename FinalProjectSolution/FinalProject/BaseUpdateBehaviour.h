#pragma once
#include <vector>
class BaseUpdateBehaviour
{
public:
	BaseUpdateBehaviour();
	~BaseUpdateBehaviour();
	virtual void Update() {};
	virtual void FixedUpdate() {};
	static std::vector<BaseUpdateBehaviour*> UpdateBehaviours;
};

