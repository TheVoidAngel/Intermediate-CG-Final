#pragma once
#include "IComponent.h"
#include "Gameplay/Physics/TriggerVolume.h"
#include "Gameplay/Components/RenderComponent.h"
#include "Gameplay/Physics/TriggerVolume.h"

class Triggers : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<Triggers> Sptr;
	Triggers();
	virtual ~Triggers();

	Gameplay::GameObject* winloser;
	Gameplay::Physics::RigidBody::Sptr rig;

	virtual void OnTriggerVolumeEntered(const std::shared_ptr<Gameplay::Physics::RigidBody>& body) override;
	virtual void OnTriggerVolumeLeaving(const std::shared_ptr<Gameplay::Physics::RigidBody>& body) override;

	virtual void RenderImGui() override;
	virtual nlohmann::json ToJson() const override;
	static Triggers::Sptr FromJason(const nlohmann::json& blob);

	MAKE_TYPENAME(Triggers);
};