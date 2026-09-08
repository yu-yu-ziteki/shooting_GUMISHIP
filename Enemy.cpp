#include "Enemy.h"
#include "Engine\\Model.h"
#include "Engine\SphereCollider.h"
#include "Bullet.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);
	transform_.rotate_ = { 1.0f, 180.0f, 1.0f };
	transform_.position_ = {(rand() % 500) / 10.0f, (rand() % 500) / 10.0f,(rand() % 500) / 10.0f };
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);

}

void Enemy::Update()
{
	
	static float time = 0.0f;
	//5tr_.position_.z += 0.2f;
	time += 0.025f;
	transform_.position_.z -= 0.3f;
	if (transform_.position_.z <= -10.0f)
	{
		transform_.position_.z = 100.0f;
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)

{

	//当たったオブジェクトがバレットなら
	if (pTarget->GetObjectName() == "Bullet")
	{
		KillMe();//バレットを消して、自分も消す
		pTarget->KillMe();
	}
}


