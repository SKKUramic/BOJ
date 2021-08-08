// 1107 리모컨
// https://www.acmicpc.net/problem/1107
// 온갖 반례를 다 통과한 끝에 성공
#include <stdio.h>
#include <stdlib.h>

int can_go[1000001] = {0, }; // 0이면 갈 수 있음, -1이면 갈 수 없음

int main(){
	int destination, broken_button, broken_number, ten_power;
	int can_channel, button_count = 0;
	scanf("%d", &destination);
	scanf("%d", &broken_button);
	for (int i = 0; i < broken_button; i++){ // 사실상 여기서 시간을 다 잡아먹음
		scanf("%d", &broken_number);
		if (broken_number == 0){can_go[0] = -1;} // 0번이 안 눌리면 채널 0에는 갈 수 없음
		for (int x = 1; x < 1000000; x++){ // x가 갈 수 없는지 확인
			ten_power = 1;
			while (ten_power < 1000000 && x / ten_power != 0){ // 못 가는 경우를 전부 조사함
				if ((x / ten_power) % 10 == broken_number){
					can_go[x] = -1;
					break;
				}
				ten_power *= 10;
			}
		}
	}
	int idx = 0;
	while (idx < 500000){ // 번호를 눌러 갈 수 있는 채널 중 가장 가까운 채널 입력
		if ((destination - idx >= 0 && can_go[destination - idx] == 0) && (destination + idx < 1000000 && can_go[destination + idx] == 0)){ // 둘 다 갈 수 있을 때, 길이가 짧은 쪽을 리턴한다.
			int len1 = 0, len2 = 0;
			int temp1 = destination - idx, temp2 = destination + idx;
			while (temp1 > 0){
				temp1 /= 10;
				len1++;
			}
			while (temp2 > 0){
				temp2 /= 10;
				len2++;
			}
			if (len1 < len2){
				can_channel = destination - idx;
				break;
			}
			else if (len1 > len2){
				can_channel = destination + idx;
				break;
			}
			else { // 길이가 같으면 아무거나 리턴
				can_channel = destination - idx;
				break;
			}
		}// 둘 다 되는 게 아니면 한 쪽만이라도 되는지 확인한다.
		else if (destination - idx >= 0 && can_go[destination - idx] == 0){
			can_channel = destination - idx;
			break;
		}
		else if (destination + idx < 1000000 && can_go[destination + idx] == 0){
			can_channel = destination + idx;
			break;
		}
		idx++;
	}
	if (idx == 500000){can_channel = 1000000;} // 그냥 대비용
	int temp = can_channel;
	if (temp == 0){ // 채널 0번이 갈 수 있는 곳일 경우 아래의 계산식에 감지되지 않으므로 따로 지정함
		button_count = 1;
	}
	while (temp > 0){
		temp /= 10;
		button_count++;
	}
	if (abs(destination - 100) < button_count + abs(can_channel - destination)){
		printf("%d", abs(destination - 100));
	}
	else {
		printf("%d", button_count + abs(can_channel - destination));
	}
}