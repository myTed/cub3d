
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



[bitmap 관련]
	bitmap offset x
	bitmap offset y
	bitmap step y


	[screen 관련]
	draw top
	draw bottom
	
	
line 하나 그릴 때 필요한 변수들 구조체
{
	t_bitmap_slice bitmap_slice;
	t_screen_slice screen_slice;
} t_drawing_info;



f: find_wall(&map, &ray, &hittedside)
{
					구조체 (지역변수) {
							distVertical
							distHorizon
							deltaDistVertical
							deltaDistHorizon
							stepVertical
							stepHorizon
					}
				bool ishitted;

				2.7.2.	distVertical, distHorizon 초기화(ray 방향에 따라)
				2.2 deltaDistVertical, deltaDistHorizon 를 ray 사용하여 초기화
				2.4	stepVertical, stepHorizon 초기화(ray 방향에 따라)
				2.5 hited 선언(0으로 초기화)
				while hit 할때까지
					distVertical VS distHorizon 비교하여, 
						distVertical, distHorizon 업데이트
						2.8.2	map.x, map.y 업데이트	
						2.8.3	hited_side 업데이트
						2.8.4	맵에서 벽이 있는지 체크
				2.0. screen에 얼마나 그릴지 계산
}


f: 레이 쏘기 (DDA) (부딪힐때 까지) (game, map, ray)
{
		hittedside 선언
		correctedDist 선언

		2.1 map 를 pos로 초기화  

		1 find_wall(&map, &ray, &hittedside);
		correctedDist 계산 (hited_side 에 따라), mapxy, ray 이용
		return correctedDist;
	}


메인 루프(game_info)
{
	t_vector	ray;//x, y
	t_map		map;//x, y
	correcttedDist;
	buffer[][];

	너비 픽셀  = 0;
	while (너비 픽셀 screen pixel 위치 < 너비 픽셀 끝)
	{
		1. 광선 벡터 업데이트(&game_info.player, &ray);
		1. find_wall_distance(&map, &ray);
		2. correcting_wall_distance
		3. fill_wall_slice();
			. find exact slice of bitmap
			. find exact slice of screen
			. buffer slice fills

		3. fill_slice_info(correcttedDist, game): bitmap 관련 변수 구조체에 채우기
			t_drawing_info drawgin_info;

			1. <drawTop, drawBottom> 을 drawHeight로계산
				(correctedDist로 drawheight 계산)	
				
			2. offset_x_bitmap (bitmap의 어떤 x지점을 그릴지 계산)
				offset_x_wall 계산  (correctedDist, pos, ray)
				<offset_x_bitmap> 계산 (offset_x_wall 사용)
			3. offset_y_bitmap 
					drawstart가 음수일 때 offset_y_bitmap 보정
					음수 아니면 offset_y_bitmap = 0
			4. stepY_Bitmap 계산 (screen에 bitmap의 bit를 얼마나 사용해서 그릴지 계산)
				 (bitmapHeight, drawHeight 이용)

		3. fill_slice_buffer_from_texture(drawing_info): buf에 1개 texture line 그리기
				offset_x_bitmap, offset_y_bitmap부터
				stepY_Bitmap 만큼 늘리면서, 비트맵의 컬러값을 가져온다.
				drawstart ~ drawend까지 컬러값을 찍어준다
					1. ceiling: buf[x][0~drawstart]
					2. wall: buf[x][drawstart~drawbottom]
					3. floor: buf[x][drawbottom~screenheight]
	
		너비 픽셀 x++;
	}
	mlx_put_image();//screen 전체 한 번 찍어주기
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
