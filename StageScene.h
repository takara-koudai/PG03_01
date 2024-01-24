#pragma once
#include "Scene.h"
#include <Novice.h>
#include "struct.h"

class StageScene : public IScene 
{
public:

	void Initialze(char* keys, char* preKeys) override;

	//void Initialize(char* keys, char* prekeys) override;

	void Update() override;

	void Draw() override;

private:

	char* keys_, * preKeys_;

	// �v���C���[
	float playerPosX; // �v���C���[�̍��WX
	float playerPosY; // �v���C���[���WY
	int playerSpeed;       // ����
	int playerSize;       // �v���C���[�̕��A����

	Object player;
	

	// �e
	float bulletPosX; // �e��X���W
	float bulletPosY; // �e��Y���W
	int bulletSpeed;    // �e�̑���
	int isBulletShot;    // �e�𔭎˂��Ă��邩�t���O
	int bulletRadius;   // �~�̔��a

	Object bullet;

	float enemyPosX;
	float enemyPosY;
	int enemySpeed;
	int enemyRadius;
	int isEnemyAlive; // �G���������Ă��邩 0:�������Ă��Ȃ��@1:�������Ă���
	int respawnTimer;

	Object enemy;

	// �����蔻����v�Z����
	float dx; // X2-X1
	float dy; // Y2-Y1

	// ||=�܂���
	// �~�̒��S�̋������v�Z����(�E��)
	int d;
	// �G�̔��a�ƒe�̔��a�𑫂���2�悷��(����)
	float ds;

};

