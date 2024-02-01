#pragma once
enum SCENE
{
	TITLE,STAGE,CLEAR,SceneMax
};

class IScene
{
protected:

	static int sceneNo;
	const char* keys_;
	const char* prekeys_;

public:

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();

	int GetSceneNo();

	void Setkeys(char* keys, char* prekeys);

};

