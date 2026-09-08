#include "GameOverScene.h"
#include "Engine/Image.h" //イメージクラスが使えるようになる
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "GameOverScene"), hGameOverPic_(-1)
{
}

void GameOverScene::Initialize()
{
	hGameOverPic_ = Image::Load("GameOver.png");
}

void GameOverScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void GameOverScene::Draw()
{
	Image::SetTransform(hGameOverPic_, transform_);
	Image::Draw(hGameOverPic_);
}

void GameOverScene::Release()
{
}
