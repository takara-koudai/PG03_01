#include "StageScene.h"

void StageScene::Initialze(char* keys, char* preKeys) 
{

	keys_ = keys;

	preKeys_ = preKeys;

	// �v���C���[
	playerPosX = 640.0f; // �v���C���[�̍��WX
	playerPosY = 360.0f; // �v���C���[���WY
	playerSpeed = 5;       // ����
	playerSize = 40;       // �v���C���[�̕��A����

	player =
	{
		{640.0f,640.0f},
		{5,5},
		40
	};

	// �e
	bulletPosX = 0.0f; // �e��X���W
	bulletPosY = 0.0f; // �e��Y���W
	bulletSpeed = 10;    // �e�̑���
	isBulletShot = 0;    // �e�𔭎˂��Ă��邩�t���O
	bulletRadius = 10;   // �~�̔��a

	bullet =
	{
		{0.0f,0.0f},
		{6,6},
		20
	};

	enemyPosX = 640;
	enemyPosY = 32;
	enemySpeed = 3;
	enemyRadius = 20;
	isEnemyAlive = 1; // �G���������Ă��邩 0:�������Ă��Ȃ��@1:�������Ă���
	respawnTimer = 120;

	enemy =
	{
		{100,100},
		{6,6},
		40
	};


}

void StageScene::Update() {

	if (isEnemyAlive == 0) {

		sceneNo = CLEAR;
	}


	if (keys_[DIK_W] || keys_[DIK_UP]) 
	{
		playerPosY -= playerSpeed;
	}
	if (keys_[DIK_S] || keys_[DIK_DOWN]) 
	{
		playerPosY += playerSpeed;
	}
	if (keys_[DIK_A] || keys_[DIK_LEFT]) 
	{
		playerPosX -= playerSpeed;
	}
	if (keys_[DIK_D] || keys_[DIK_RIGHT]) 
	{
		playerPosX += playerSpeed;
	}


	// �e�����˂���Ă��Ȃ�������
	if (isBulletShot == false) {

		// �X�y�[�X�L�[���������u��
		if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE] == 0) {
			// �e�𔭎˂���
			isBulletShot = true;

			// �e�̍��W�ƃv���C���[�̍��W���ꏏ�ɂȂ�
			bulletPosX = playerPosX;
			bulletPosY = playerPosY;
		}
	}

	if (isBulletShot == true) {
		// �e����ɔ���
		bulletPosY = bulletPosY - bulletSpeed;

		// �����e����ʂ̊O�ɏo����
		if (bulletPosY <= 0) {
			// �e�𔭎˂��Ă��邩�t���O��false(0)�ɂ���
			// ���˂ł���悤�ɂ���
			isBulletShot = false;
			bulletPosY = -4;
		}
	}

	// �����蔻����v�Z����
	dx = enemyPosX - bulletPosX; // X2-X1
	dy = enemyPosY - bulletPosY; // Y2-Y1

	// ||=�܂���
	// �~�̒��S�̋������v�Z����(�E��)
	d = (int)dx * (int)dx + (int)dy * (int)dy;
	// �G�̔��a�ƒe�̔��a�𑫂���2�悷��(����)
	ds = (float)(enemyRadius + bulletRadius) * (float)(enemyRadius + bulletRadius);
	// ���� == �E�� �܂���{ || } ���� > �E�� ���@
	if (ds == d || ds > d) {
		// �������Ă���
		isBulletShot = false;
		bulletPosY = -4;
		// �G������(�t���O��p�ӂ���)
		isEnemyAlive = false;
	}


	if (isEnemyAlive == true) 
	{
		enemyPosX += enemySpeed;

		if (enemyPosX >= 1260) {

			enemySpeed *= -1;
		}
		// ���[�ɖ߂�����
		if (enemyPosX <= 20) {

			enemySpeed *= -1;
		}
	}



}

void StageScene::Draw() {
	if (isBulletShot == true) 
	{

		// �e��`��
		Novice::DrawTriangle(
			(int)bulletPosX,           // ��X
			(int)bulletPosY - 10, // ��Y
			(int)bulletPosX - 10, // ����X
			(int)bulletPosY + 20 - 10, // ����Y
			(int)bulletPosX + 10,      // �E��X
			(int)bulletPosY + 20 - 10, // �E��Y

			RED, kFillModeSolid);
	}

	// �����蔻��̉~��`��
	if (isEnemyAlive == true) 
	{

		Novice::DrawEllipse(
			(int)enemyPosX, (int)enemyPosY, enemyRadius, enemyRadius, 0.0f, WHITE, kFillModeSolid);

		Novice::DrawEllipse(
			(int)enemyPosX, (int)enemyPosY, enemyRadius + 2, enemyRadius + 2, 0.0f, WHITE,
			kFillModeSolid);
	}



	// �v���C���[��`��
	Novice::DrawBox(
		(int)playerPosX - playerSize / 2, (int)playerPosY - playerSize / 2, playerSize, playerSize,
		0.0f,
		WHITE, kFillModeSolid);



	Novice::ScreenPrintf(0, 50, "%c", keys_[DIK_SPACE]);

	Novice::ScreenPrintf(0, 0, "Game");

}
