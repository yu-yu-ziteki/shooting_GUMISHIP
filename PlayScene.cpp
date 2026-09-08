#include "PlayScene.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Engine\SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize()
{

//	hModel_ = Model::Load("Oden.fbx");

	player = Instantiate<Player>(this); //プレイヤーのインスタンス　＝　プレイヤーオブジェクトを作る
	for (int i = 0; i <= 10;i++) {
		Instantiate<Enemy>(this);
	}
	XMFLOAT3 pPos = player->GetPosition();
	//Instantiate<Bullet>(this);
	Camera::SetPosition(XMFLOAT3(pPos.x, pPos.y + 2.0f, pPos.z - 10.0f));
	Camera::SetTarget(XMFLOAT3(pPos.x, pPos.y, pPos.z));
}

void PlayScene::Update()
{
	XMFLOAT3 pPos = player->GetPosition();
	Camera::SetPosition(XMFLOAT3(pPos.x, pPos.y + 2.0f, pPos.z - 10.0f));
	Camera::SetTarget(XMFLOAT3(pPos.x, pPos.y, pPos.z));
	if (FindObject("Enemy") == nullptr) {
		
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
	if (Input::IsKeyDown(DIK_G))
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}

