
맵 관련 구조체
{
	북쪽 텍스처 경로
	남쪽 텍스처 경로
	서족 텍스처 경로
	동쪽 텍스처 경로
	천장 RGB
	바닥 RGB
	맵 2차원 배열 포인터
	맵 실패 여부
} map_info;

플레이어 구조체
{
	double	x;
	double y;
} pos;

플레이어 시선 구조체
{
	double	x;
	double	y;
} dir;

프로젝션 플레인 구조체
{
	double x;
	double y;
} view;

광선 구조체
{
	double x;
	double y;
} ray;

맵 구조체
{
	int	x;
	int	y;
} map;

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

광선 벡터 업데이트
{
	// view_factor range (-1 ~ 1)
	view_factor_range = (2 * width_idx / SCREEN_WIDTH) - 1;
	ray.x = dir.x + (view.x * view_factor_range);
	ray.y = dir.y + (view.y * view_factor_range);
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
	while (너비 픽셀 위치 < 너비 픽셀 끝)
	{
		1. 광선 벡터 업데이트
		2. 레이 쏘기 (DDA) (부딪힐때 까지)
		3. 광선 수직 거리 계산
		4. 수직거리에 해당하는 높이 계산
		5. 높이 그리기
		너비 픽셀++;
	}
}

메인 작성
{
	1. 맵 관련 구조체 초기화
	1. 맵 파싱
	2. 키 훅 등록
	3. 메인 루프 등록
	4. 루프 시작
}