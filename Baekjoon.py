"""
파이썬에서의 heap은 min_heap만 존재. import heapq 를 해야함
heapq.heappush(heap, value) 로 push 

max_heap의 경우는 넣고자 하는 int a에 대하여 (-a, a)의 튜플 형태로 저장 or 음수 저장
이후 접근할때는 [i][0] * -1 혹은 [i][1]로 접근하여 값을 사용
이번 문제에서는 음수값을 넣는 방식을 차용
"""

import sys
import heapq

input = int(sys.stdin.readline())
max_heap = []
min_heap = []

for i in range(input):
	temp = int(sys.stdin.readline())

	if len(max_heap)==len(min_heap):
		heapq.heappush(max_heap, -temp)
	else:
		heapq.heappush(min_heap, temp)
# len(max_heap) >= len(min_heap) 유지

	if len(min_heap)>=1 and max_heap[0] * -1 > min_heap[0]:
		max=heapq.heappop(max_heap)# top의 값이 반환
		min=heapq.heappop(min_heap)
		heapq.heappush(max_heap, -min)
		heapq.heappush(min_heap, -max)

	print(max_heap[0] * -1)