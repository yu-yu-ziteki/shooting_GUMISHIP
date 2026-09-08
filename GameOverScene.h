#pragma once
#include "engine\\GameObject.h"
class GameOverScene :
	public GameObject
{
public:
	GameOverScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

private:
	int hGameOverPic_;	//モデルのハンドル


};

