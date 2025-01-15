import pandas as pd
import matplotlib.pyplot as plt

# 读取 CSV 文件

import os

data = pd.read_csv('../src/build/strategy_trajectory_data.csv', delimiter='\t')

# 提取需要的数据列
time = data['time']
velocity = data['velocity']
pitch_theta = data['pitch_theta']
position_x = data['position_x']
position_y = data['position_y']
alpha = data['alpha']
delta_z = data['delta_z']

# 创建图形并设置子图
fig, axs = plt.subplots(2, 2, figsize=(10, 8))

# 绘制 y-x 曲线 (position_y vs position_x)
axs[0, 0].plot(position_x, position_y, label='y-x trajectory', color='b')
axs[0, 0].set_xlabel('Position X')
axs[0, 0].set_ylabel('Position Y')
axs[0, 0].set_title('y-x Curve')
axs[0, 0].grid(True)

# 绘制 V-t 曲线 (velocity vs time)
axs[0, 1].plot(time, velocity, label='Velocity vs Time', color='g')
axs[0, 1].set_xlabel('Time (s)')
axs[0, 1].set_ylabel('Velocity (m/s)')
axs[0, 1].set_title('Velocity vs Time')
axs[0, 1].grid(True)

# 绘制 alpha-t 曲线 (alpha vs time)
axs[1, 0].plot(time, alpha, label='Alpha vs Time', color='r')
axs[1, 0].set_xlabel('Time (s)')
axs[1, 0].set_ylabel('Alpha (rad)')
axs[1, 0].set_title('Alpha vs Time')
axs[1, 0].grid(True)

# 绘制 theta-t 曲线 (pitch_theta vs time)
axs[1, 1].plot(time, pitch_theta, label='Pitch Theta vs Time', color='purple')
axs[1, 1].set_xlabel('Time (s)')
axs[1, 1].set_ylabel('Pitch Theta (rad)')
axs[1, 1].set_title('Pitch Theta vs Time')
axs[1, 1].grid(True)

# 调整布局
plt.tight_layout()

# 显示图形
plt.show()
