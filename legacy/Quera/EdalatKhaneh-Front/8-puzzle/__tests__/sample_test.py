import os
import pprint
import re
import subprocess
import sys
import unittest
from unittest.util import three_way_cmp
from selenium import webdriver
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities


def _cmp_test_names(x, y):
    m1 = re.match(r'test_(\d+)_.*', x)
    m2 = re.match(r'test_(\d+)_.*', y)
    if m1 and m2:
        return three_way_cmp(int(m1.group(1)), int(m2.group(1)))
    return three_way_cmp(x, y)


unittest.TestLoader.sortTestMethodsUsing = lambda _, x, y: _cmp_test_names(x, y)

DEBUG = 'PRODUCTION' not in os.environ

SRC_PATH = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

init_state = [
    [2, 3, 5],
    [1, 4, ''],
    [7, 8, 6]
]


class SimpleTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        print('DEBUG = {}'.format(DEBUG), file=sys.stderr)
        cls.server = subprocess.Popen(['python3', '-m', 'http.server', '9988'], cwd=SRC_PATH, stderr=subprocess.DEVNULL)

        desired_capabilities = dict({'loggingPrefs': {'browser': 'ALL'}}, **DesiredCapabilities.CHROME)

        if DEBUG:
            cls.driver = webdriver.Chrome(
                executable_path="/home/mreza/chrome_exec_path/chromedriver_linux64/chromedriver",
                desired_capabilities=desired_capabilities)
        else:
            cls.driver = webdriver.Remote(
                command_executor='http://localhost:4444/wd/hub',
                desired_capabilities=desired_capabilities
            )

        cls.driver.implicitly_wait(1)
        cls.driver.get('http://127.0.0.1:9988/index.html')

    # helper function used to move cell
    def move_cell(self, action):
        for i in action:
            cell = self.driver.find_element_by_id(str(i))
            cell.click()

    # helper function checks the final state of board
    def check_final_state(self):
        correct = False
        cells = self.driver.find_elements_by_class_name('cell')
        self.assertEqual(len(cells), 9)
        for i in cells:
            element_id = int(i.get_attribute('id'))
            if i.text != '':
                if int(i.text) == int(element_id) + 1:
                    correct = True
                else:
                    correct = False
                    break

        self.assertAlmostEqual(correct, True)

    # test checks cell content
    def test_check_cell_content(self):
        correct = False
        cells = self.driver.find_elements_by_class_name('cell')
        self.assertEqual(len(cells), 9)
        for i in cells:
            element_id = int(i.get_attribute('id'))
            y = int(element_id / 3)
            x = int(element_id % 3)
            if i.text != '':
                if int(i.text) == init_state[y][x]:
                    correct = True
                else:
                    correct = False
                    break

        self.assertAlmostEqual(correct, True)

    def test_game_play_1(self):
        actions = [2, 8, 5, 2, 8, 5, 2, 1, 0, 2, 1, 0, 2, 1, 0, 3, 4, 5, 8, 6, 7, 8, 6, 7, 8]
        reset_btn = self.driver.find_element_by_class_name('btn')
        reset_btn.click()

        self.move_cell(actions)

        moves = self.driver.find_element_by_id('moves')
        self.assertEqual(int(moves.text), len(actions))
        self.check_final_state()

    @classmethod
    def tearDownClass(cls):
        console_logs = []
        for log_item in cls.driver.get_log('browser'):
            if log_item.get('source') == 'network' and 'favicon.ico - Failed to load' in log_item.get('message'):
                continue
            console_logs.append(log_item)
        if console_logs:
            print('\n--------------------\nBROWSER CONSOLE LOG:\n-----', file=sys.stderr)
            for log_item in console_logs[:10]:
                log_item['message'] = log_item['message'][:200]
                print(pprint.pformat(log_item), '-----', sep='\n', file=sys.stderr)
        cls.server.kill()
        cls.driver.close()


if __name__ == '__main__':
    unittest.main()
