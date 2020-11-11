
#include "All.h"

PlayerClass player(Vec2(50,150),Vec2(1,1),255,0);

Enemy enemy[5] = { 
	Enemy(Vec2(0, 0), Vec2(1, 1), 255, 0,player),
	Enemy(Vec2(350, 100), Vec2(1, 1), 255, 0,player),
	Enemy(Vec2(400, 150), Vec2(1, 1), 255, 0,player),
	Enemy(Vec2(450, 200), Vec2(1, 1), 255, 0,player),
	Enemy(Vec2(500, 250), Vec2(1, 1), 255, 0,player)
};

//std::vector<ObjectClass*> listPlayer;
//std::vector<ObjectClass*> listEnemy[5];

// ゲーム処理
void GameProcessing();
// 描画処理
void DrawProcessing();

/*
	エントリポイント
*/
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmpLine,
	_In_ INT       nCmdShow)
{
	// エンジンの初期化
	// ゲームループ開始前に1度だけ実行する
	if (Engine::Initialize(640, 480, "Sample") == false)
	{
		return 0;
	}

	
	//listPlayer.push_back(&Player);
	player.Init();
	
	for (int enemyCount = 0; enemyCount < 5; enemyCount++) {
		//listEnemy[enemyCount].push_back(&Enemy[enemyCount]);
		enemy[enemyCount].Init();
	}

	while (true)
	{
		bool message_ret = false;
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else 
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			// ゲーム処理
			GameProcessing();

			// 描画開始
			DrawProcessing();
		}
	}

	// エンジン終了
	// ゲームループ終了後に1度だけ実行する
	// テクスチャとサウンドファイルも全て解放する
	Engine::Release();

	// メモリリーク検出
	_CrtDumpMemoryLeaks();

	return 0;

} // プログラム終了

void GameProcessing()
{
	// 入力データの更新
	Engine::Update();

	player.Update();

	for (int enemyCount = 0; enemyCount < 5; enemyCount++) {
		enemy[enemyCount].Update();
	}
}

void DrawProcessing()
{
	// 描画開始
	Engine::StartDrawing(0);

	player.Draw();

	for (int enemyCount = 0; enemyCount < 5; enemyCount++) {
		enemy[enemyCount].Draw();
	}

	// 描画終了
	Engine::FinishDrawing();
}
