#include <Novice.h>

const char kWindowTitle[] = "LC1C_20_タナカコウダイ_タイトル";

typedef struct Vector
{
	float x;
	float y;
}Vector;

typedef struct Object
{
	Vector position;
	Vector speed;
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Object player =
	{
		{640,660},
		{5,5}
	};
	int playerradius = 40;

	Object enemy =
	{
		{100,100},
		{6,6}
	};
	int radius = 40;

	//弾
	Object bullet =
	{
		{0,0},
		{5,5}
	};
	int Bulletraedius = 20;

	bool bulletflag = false;





	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (keys[DIK_W])
		{
			player.position.y -= player.speed.y;
		}
		if (keys[DIK_A])
		{
			player.position.x -= player.speed.x;
		}
		if (keys[DIK_S])
		{
			player.position.y += player.speed.y;
		}
		if (keys[DIK_D])
		{
			player.position.x += player.speed.x;
		}

		//敵移動
		enemy.position.x += enemy.speed.x;

		if (enemy.position.x + 40 >= 1280)
		{
			enemy.speed.x = enemy.speed.x * -1;
		}

		if (enemy.position.x - 40 <= 0)
		{
			enemy.speed.x = enemy.speed.x * -1;
		}

		//弾発射
		if (bulletflag == false)
		{
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				bulletflag = true;

				bullet.position.x = player.position.x;
				bullet.position.y = player.position.y;
			}
		}

		if (bulletflag == true)
		{
			bullet.position.y -= bullet.speed.y;

			if (bullet.position.x <= enemy.position.x + radius &&
				enemy.position.x <= bullet.position.x + Bulletraedius &&
				bullet.position.y <= enemy.position.y + radius &&
				enemy.position.y <= bullet.position.y + Bulletraedius)
			{
				bulletflag = false;
			}
		}

		if (bullet.position.y <= 0)
		{
			bulletflag = false;
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		if (bulletflag == true)
		{
			Novice::DrawBox(bullet.position.x + 5, bullet.position.y, Bulletraedius, Bulletraedius, 0.0f, BLACK, kFillModeSolid);
		}

		Novice::DrawBox(player.position.x, player.position.y, playerradius, playerradius, 0.0f, WHITE, kFillModeSolid);

		Novice::DrawBox(enemy.position.x, enemy.position.y, radius, radius, 0.0f, RED, kFillModeSolid);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
