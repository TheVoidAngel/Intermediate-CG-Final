#pragma once
#include "IComponent.h"
struct GLFWwindow;

class MainCharMove : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<MainCharMove> Sptr;

	MainCharMove();
	virtual ~MainCharMove();

	virtual void Update(float deltaTime) override;

public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(MainCharMove);
	virtual nlohmann::json ToJson() const override;
	static MainCharMove::Sptr FromJson(const nlohmann::json& blob);

protected:
	glm::vec3 _speed;

};