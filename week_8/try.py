import sys
import matplotlib.pyplot as plt

def main():
    if len(sys.argv) < 2:
        print("Usage: python try.py <input_file>")
        return

    input_file = sys.argv[1]

    with open(input_file, 'r') as file:
        lines = file.readlines()

    # Read n and m from the first line
    n, m = map(int, lines[0].split())

    polygon_points = []
    separate_points = []

    # Read the next n lines for polygon points
    for i in range(1, n + 1):
        x, y = map(float, lines[i].split())
        polygon_points.append((x, y))

    # Read the next m lines for separate points
    for i in range(n + 1, n + 1 + m):
        x, y = map(float, lines[i].split())
        separate_points.append((x, y))

    # Unzip the polygon points into two lists: x and y coordinates
    polygon_x, polygon_y = zip(*polygon_points)
    # Close the polygon by adding the first point at the end
    polygon_x += (polygon_x[0],)
    polygon_y += (polygon_y[0],)

    # Unzip the separate points into two lists: x and y coordinates
    separate_x, separate_y = zip(*separate_points)

    # Plot the polygon
    plt.plot(polygon_x, polygon_y, marker='o', label='Polygon')

    # Plot the separate points
    plt.scatter(separate_x, separate_y, color='red', label='Separate Points')

    # Add labels and legend
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Polygon and Separate Points')
    plt.legend()

    # Show the plot
    plt.show()

if __name__ == "__main__":
    main()