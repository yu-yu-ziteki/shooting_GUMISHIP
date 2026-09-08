#pragma once
#include "engine\\GameObject.h"
class ClearScene :
    public GameObject
{
public:
	ClearScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
private:
	int hClearPic_;	//モデルのハンドル


};

