
맵 관련 구조체
{
	북쪽 텍스처 이미지
	남쪽 텍스처 이미지
	서족 텍스처	이미지
	동쪽 텍스처 이미지
	천장 RGB
	바닥 RGB
	맵 2차원 배열 포인터
} map_info;


맵 구조체
{
	int	x;
	int	y;
} t_map;

백터 구조체
{
	double x;
	double y;
} vector;

플레이 구조체
{
	vector pos;
	vector dir;
	vector view;
} 플레이어


game 구조체
{
	t_map_info	map;
	t_player	player;
} game_info;



맵 관련 구조체 초기화
{
	= 0;
}

맵 파싱
{
	맵을 파싱하면서, 구조체에다가 실제 값을 집어 넣는다.
	하고 에러 체크까지.
}

키 훅 루프
{
	1. 방향키를 누른 경우
	2. 회전키를 누른 경우
	3. esc 누른 경우
}

광선 벡터 업데이트(const *p_player, int width_idx, t_vector *p_ray);
{
	// view_factor range (-1 ~ 1)
	double view_factor = (2 * width_idx / SCREEN_WIDTH) - 1;
	ray.x = dir.x + (view.x * view_factor);
	ray.y = dir.y + (view.y * view_factor);
}

레이쏘기(DDA)
{

	while(벽에 히트했으면)
	{
		
	}
}

메인 루프
{
	너비 픽셀  = 0;
	t_vector	ray;
	while (너비 픽셀 위치 < 너비 픽셀 끝)
	{
		1. 광선 벡터 업데이트(&game_info.player, &ray);
		2. 레이 쏘기 (DDA) (부딪힐때 까지)
		3. 광선 수직 거리 계산
		4. 수직거리에 해당하는 높이 계산
		5. 높이 그리기
		너비 픽셀++;
	}
}

메인 루프(game_info)
{
	너비 픽셀  = 0;
	t_vector	ray;
	t_map		map;

	while (너비 픽셀 위치 < 너비 픽셀 끝)
	{
		1. 광선 벡터 업데이트(&game_info.player, &ray);
		2. 레이 쏘기 (DDA) (부딪힐때 까지)
			2.1 map 를 pos로 초기화  
			2.2 deltaDistVertical, deltaDistHorizon 를 ray 사용하여 초기화
			2.3 correctedDist 선언
			2.4	stepVertical, stepHorizon 선언
			2.5 hited 선언(0으로 초기화)
			2.6 hited_side 선언
			2.7 ray 방향에 따라
				2.7.1.  stepVertical, stepHorizon 초기화
				2.7.2.	distVertical, distHorizon 초기화
			2.8 히트 할때까지
				2.8.1.	distVertical VS distHorizon 비교하여, 
						distVertical, distHorizon 업데이트
				2.8.2	map.x, map.y 업데이트
				2.8.3	hited_side 업데이트
				2.8.4	맵에서 벽이 있는지 체크
			2.9	correctedDist 계산 (hited_side 에 따라)
			2.10. 수직거리에 해당하는 높이 계산
		4. 높이 그리기
		너비 픽셀++;
	}
}



메인 작성
{
	t_game_info game_info;

	1. 맵 관련 구조체 초기화(&game_info)
	2. 맵 파싱(&game_info);

	3. 키 훅 등록
	4. 메인 루프 등록(&game_info);
	5. 루프 시작
}
