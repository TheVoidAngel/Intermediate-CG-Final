#include "Gameplay/Components/MainCharMove.h"
#include <GLM/gtc/quaternion.hpp>
#include <GLFW/glfw3.h>
#include "Gameplay/GameObject.h"
#include "Gameplay/Scene.h"
#include "Gameplay/InputEngine.h"
#include "Utils/JsonGlmHelpers.h"
#include "Utils/ImGuiHelper.h"
#include "Application/Application.h"
#define GLM_SWIZZLE

nlohmann::json MainCharMove::ToJson() const {
	return nlohmann::json();
}

MainCharMove::MainCharMove() :
	IComponent(),
	_speed(3.0f) {

}

MainCharMove::~MainCharMove() = default;

MainCharMove::Sptr MainCharMove::FromJson(const nlohmann::json& blob) {
	return MainCharMove::Sptr();
}

void MainCharMove::Update(float deltaTime) {
	if (Application::Get().IsFocused) {
		glm::vec3 speedDir = glm::vec3(0.0f);

		if (InputEngine::IsKeyDown(GLFW_KEY_A)) {
			speedDir.y += _speed.x;
		}
		if (InputEngine::IsKeyDown(GLFW_KEY_D)) {
			speedDir.y -= _speed.x;
		}
		if (InputEngine::IsKeyDown(GLFW_KEY_W)) {
			speedDir.x += _speed.y;
		}
		if (InputEngine::IsKeyDown(GLFW_KEY_S)) {
			speedDir.x -= _speed.y;
		}
		speedDir *= deltaTime;
		GetGameObject()->SetPostion(GetGameObject()->GetPosition() + speedDir);
	}
}

void MainCharMove::RenderImGui(){}