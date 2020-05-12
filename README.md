
## Rendering Text Plate Dataset


딥러닝 모델 학습시 Dataset 으로 활용하기 위해 Text Plate 를 영상처리를 통해 배경에 합성해 원하는 만큼 Annotation 이 있는 Dataset 을 제작 할 수 있도록 개발

----------

두 가지 버전의 Rendering 코드 개발<br><br>


**1. Rendering in Random Location**
 
- 크롤링 한 창고 이미지 셋에서, 글자 및 위치와 각도를 Random 하게 plate를 렌더링<br>

<img src = "https://user-images.githubusercontent.com/25008566/81750546-8e1a1000-9462-11ea-9465-13e1b6108dd0.jpg" width="300"/> <img src = "https://user-images.githubusercontent.com/25008566/81750263-03391580-9462-11ea-9468-28d44de364fe.png" width="300"/>



 <br>

**2. Rendering in Apriltag Location**

- 실제 창고 사진에서 Apriltag 가 있는 곳을 탐지하고, 그 위치에 맞게 plate 를 렌더링 
 <img width="600" alt="스크린샷 2020-05-12 오후 3 14 32" src="https://user-images.githubusercontent.com/25008566/81750932-4f388a00-9463-11ea-9534-8f315773d727.png">

<br>

기타 utility 스크립트 
- Google 에서 키워드 이미지 크롤링
<br><br>

## Execute  

-------

#### 1. Rendering in Random Location <br><br>

  - Dependencies
    - opencv / sophus / eigen3

  - prepare background data
    > put in ./background folder




------

#### 2. Rendering in Apriltag Location


Dependencies
 - working in motion2ai build environment

