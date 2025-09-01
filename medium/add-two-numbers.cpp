// T: O(n) where n = max(n1, n2)
// S: O(1)
// Valid when the sum is within int/long range

int getNumber(ListNode* temp) {
    int idx = 0, num = 0;

    while (temp != nullptr) {
        int n = temp->val;
        num += n * pow(10, idx++);
        temp = temp->next;
    }

    return num;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int num1 = getNumber(l1), num2 = getNumber(l2), res = num1 + num2;

    ListNode *head = nullptr, *temp = nullptr;

    if (res == 0) return new ListNode(0);

    while (res > 0) {
        if (head == nullptr) {
            head = new ListNode(res % 10);
            temp = head;
        }
        else {
            ListNode *temp2 = new ListNode(res % 10);
            temp->next = temp2;
            temp = temp2;
        }

        res = res / 10;
    }

    return head;
}




// T: O(n) where n = max(n1, n2)
// S: O(n)

string getSum(ListNode* t1, ListNode* t2) {
    string sum("");

    int carry = 0;

    while (t1 != nullptr && t2 != nullptr) {
        int val1 = t1->val, val2 = t2->val, res = val1 + val2 + carry;
        carry = 0;
        if (res > 9) carry = 1;

        sum += to_string(res % 10);
        t1 = t1->next;
        t2 = t2->next;
    }


    while (t1 != nullptr) {
        int n = t1->val;
        if (carry == 1) n += carry;
        carry = 0;
        if (n > 9) carry = 1;
        sum += to_string(n % 10);
        t1 = t1->next;
    }

    while (t2 != nullptr) {
        int n = t2->val;
        if (carry == 1) n += carry;
        carry = 0;
        if (n > 9) carry = 1;
        sum += to_string(n % 10);
        t2 = t2->next;
    }

    if (carry == 1) sum += "1";

    return sum;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    string sum = getSum(l1, l2);
    int idx = 0;

    ListNode *head = nullptr, *temp = nullptr;

    while (idx < sum.length()) {
        if (head == nullptr) {
            head = new ListNode(sum[idx++] - '0');
            temp = head;
        }
        else {
            ListNode *temp2 = new ListNode(sum[idx++] - '0');
            temp->next = temp2;
            temp = temp2;
        }
    }

    return head;
}


// T: O(n) where n = max(n1, n2)
// S: O(1)

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode *head = nullptr, *temp = nullptr;
    int carry = 0, res;

    while (l1 || l2 || carry) {
        res = 0;

        if (l1 && l2) {
            res = l1->val + l2->val;
        }
        else if (l1) res = l1->val;
        else if (l2) res = l2->val;

        if (carry) {
            res += carry;
            carry = 0;
        }

        if (!head) {
            head = new ListNode(res % 10);
            temp = head;
        }
        else {
            ListNode *temp2 = new ListNode(res % 10);
            temp->next = temp2;
            temp = temp2;
        }

        carry = res / 10;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return head;
}
