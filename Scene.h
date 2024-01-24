#pragma once

enum Scene { TITLE, STAGE, CLEAR };

class IScene {
protected:
	//�V�[���ԍ����Ǘ�����ϐ�
	static int sceneNo;

public:
	//
	//
	virtual void Init(char* keys, char* preKeys) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//
	virtual ~IScene();
	//
	int GetSceneNo();
};

