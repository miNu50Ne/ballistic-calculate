import numpy as np
import matplotlib.pyplot as plt

# 读取 CSV 文件
data = np.loadtxt('../src/build/missile_trajectory.csv', delimiter='\t', skiprows=1)

# 提取各列数据
t = data[:, 0]      # 时间 (秒)
V = data[:, 1]      # 速度 (m/s)
theta = data[:, 2]  # 俯仰角 (rad)
x = data[:, 3]      # 位置 x (m)
y = data[:, 4]      # 位置 y (m)
alpha = data[:, 5]  # 俯仰角度 (rad)
delta_z = data[:, 6]# 控制输入 (rad)

# 绘制 y-x 曲线
plt.figure(figsize=(12, 8))
plt.subplot(2, 2, 1)
plt.plot(x, y, label="y-x")
plt.xlabel('x (m)')
plt.ylabel('y (m)')
plt.title('y-x 曲线')
plt.grid(True)

# 绘制 V-t 曲线
plt.subplot(2, 2, 2)
plt.plot(t, V, label="V-t", color='orange')
plt.xlabel('时间 (t) (秒)')
plt.ylabel('速度 (V) (m/s)')
plt.title('V-t 曲线')
plt.grid(True)

# 绘制 alpha-t 曲线
plt.subplot(2, 2, 3)
plt.plot(t, alpha, label="alpha-t", color='green')
plt.xlabel('时间 (t) (秒)')
plt.ylabel('俯仰角度 (α) (rad)')
plt.title('α-t 曲线')
plt.grid(True)

# 绘制 delta_z-t 曲线
plt.subplot(2, 2, 4)
plt.plot(t, delta_z, label="delta_z-t", color='red')
plt.xlabel('时间 (t) (秒)')
plt.ylabel('控制输入 (δ_z) (rad)')
plt.title('δ_z-t 曲线')
plt.grid(True)

# 自动调整布局并显示
plt.tight_layout()
plt.show()
