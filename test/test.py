import re
import matplotlib.pyplot as plt
import statistics

def extract_delay_times(file_path):
    delay_times = []

    with open(file_path, 'r') as file:
        for line in file:
            # Search for the pattern "Simulated Network Delay:"
            if "Simulated Network Delay:" in line:
                # Extract the time value using regular expression
                match = re.search(r'\d+\.\d+', line)
                if match:
                    delay_time = float(match.group())
                    delay_times.append(delay_time)

    return delay_times

def plot_delay_times(delay_times):
    plt.plot(delay_times, marker='o')
    plt.title('Simulated Network Delay Over Time')
    plt.xlabel('Sample Number')
    plt.ylabel('Delay Time (ms)')
    plt.grid(True)
    plt.show()

def print_statistics(delay_times):
    if delay_times:
        average_delay = statistics.mean(delay_times)
        median_delay = statistics.median(delay_times)
        min_delay = min(delay_times)
        max_delay = max(delay_times)

        print(f"Average Delay: {average_delay:.4f} ms")
        print(f"Median Delay: {median_delay:.4f} ms")
        print(f"Minimum Delay: {min_delay:.4f} ms")
        print(f"Maximum Delay: {max_delay:.4f} ms")
    else:
        print("No delay times found in the file.")

# Replace 'your_file_path.txt' with the actual path to your file
file_path = 'lte/lte.txt'
# file_path = 'wifi/wifi.txt'

# Extract delay times from the file
delay_times = extract_delay_times(file_path)

# Print statistics for the extracted delay times
print_statistics(delay_times)

plot_delay_times(delay_times)