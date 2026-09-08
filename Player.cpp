#include "Player.h"
#include "Engine\\Model.h"
#include "Engine\\input.h"
#include "Bullet.h"

Player::Player(GameObject* parent)

	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Gumi.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0.0f, -2.0f, 0.0f };
	transform_.scale_ = { 1.0f,1.0f, 1.0f };
	//tr_.rotate_ = { 90.0f,90.0f, 90.0f };
}

void Player::Update()
{
	
	if (Input::IsKey(DIK_UP) || Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.2f;

	}
	if (Input::IsKey(DIK_DOWN) || Input::IsKey(DIK_S))
	{
		transform_.position_.y -= 0.2f;

	}
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.2f;
		transform_.rotate_.z = +20.0f;

	}
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.2f;
		transform_.rotate_.z = -20.0f;

	}

	if (Input::IsKeyDown(DIK_SPACE))
	{
		Bullet *pBullet = Instantiate<Bullet>(this->GetParent());
		pBullet->SetPosition(transform_.position_); 
	}
}


void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
